extern crate rodio;

use std::time::Duration;
use rodio::{OutputStream, Sink};
use rodio::source::{SineWave, Source};

fn main() {
    let (_stream, stream_handle) = OutputStream::try_default().unwrap();

    let sink1 = Sink::try_new(&stream_handle).unwrap();
    let sink2 = Sink::try_new(&stream_handle).unwrap();

    let source1 = SineWave::new(210.0 * (3.0/2.0)).take_duration(Duration::from_secs_f32(2.0)).amplify(0.2);
    let source2 = SineWave::new(210.0).take_duration(Duration::from_secs_f32(2.0)).amplify(0.2);

    let thread1 = std::thread::spawn(move || {
        sink1.append(source1);
        sink1.sleep_until_end(); // Sleep until source1 finishes
    });

    let thread2 = std::thread::spawn(move || {
        sink2.append(source2);
        sink2.sleep_until_end(); // Sleep until source2 finishes
    });

    thread1.join().unwrap();
    thread2.join().unwrap();
}
