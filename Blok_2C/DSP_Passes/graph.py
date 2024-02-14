import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a DataFrame
df = pd.read_csv('output.csv')

# Print column names
print("Column names:", df.columns)

# Plotting
plt.plot(df['Time'], df['Sample'])
plt.xlabel('Time')
plt.ylabel('Sample')
plt.title('Sample vs Time')
plt.grid(True)
plt.show()
