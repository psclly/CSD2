extern crate rodio;


use std::time::Duration;
use rodio::{OutputStream, Sink};
use rodio::source::{SineWave, Source};
fn main() {

    
    let (_stream, stream_handle) = OutputStream::try_default().unwrap();
    let sink = Sink::try_new(&stream_handle).unwrap();
    
    // Add a dummy source of the sake of the example.
    let source1 = SineWave::new(210.0 * (3.0/2.0)).take_duration(Duration::from_secs_f32(2.0)).amplify(0.2);
    let source2 = SineWave::new(210.0).take_duration(Duration::from_secs_f32(2.0)).amplify(0.2);
    sink.append(source1);
    sink.append(source2);
    
    // The sound plays in a separate thread. This call will block the current thread until the sink
    // has finished playing all its queued sounds.
    sink.sleep_until_end();
    
}