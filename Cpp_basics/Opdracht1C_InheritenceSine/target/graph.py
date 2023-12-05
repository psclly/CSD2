import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a DataFrame
data = pd.read_csv('output.csv')  # Replace 'your_data.csv' with your file name
print(data.columns)
# Extract 'time' and 'value' columns
time = data['Time']  # Replace 'time_column_name' with your time column name
value = data['Sample']  # Replace 'value_column_name' with your value column name



# Plotting the data
plt.figure(figsize=(10, 20))  # Adjust figure size if needed
plt.plot(time, value, marker='o', linestyle='-', linewidth=0.01)
plt.xlabel('Phase')
plt.ylabel('Sample')
plt.title('Oscillator')
plt.grid(True)
plt.show()