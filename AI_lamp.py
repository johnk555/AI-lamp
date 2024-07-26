import pandas as pd
from sklearn.linear_model import LinearRegression

# Load the data from the CSV file
data = pd.read_csv('AI_lamp_modified.csv')

# Split the data into input (X) and output (y) variables
X = data["LDR"].values.reshape(-1, 1)
y = data["LED"].values.reshape(-1, 1)

# Create a linear regression model
model = LinearRegression()

# Train the model using the training sets
model.fit(X, y)
w = model.coef_[0][0]
b = model.intercept_[0]
# Print the coefficients and intercept
print("Coefficients (Weights):", w)
print("Intercept (Bias):", b)

#predict on a sample value
prediction = w * 83 + b
print("Prediction for a value of 83:", prediction)