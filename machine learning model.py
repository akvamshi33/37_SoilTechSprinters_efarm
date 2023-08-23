# -*- coding: utf-8 -*-


pip install tensorflow

import pandas as pd

data=pd.read_csv('TARP.csv')
data.shape

data.columns

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.impute import SimpleImputer
from sklearn.pipeline import Pipeline
from sklearn.metrics import accuracy_score


data = pd.read_csv("TARP.csv")


X = data.drop("Status", axis=1)
y = data["Status"]


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


pipeline = Pipeline([
    ('imputer', SimpleImputer(strategy='mean')),
    ('classifier', RandomForestClassifier())
])


pipeline.fit(X_train, y_train)


y_pred = pipeline.predict(X_test)


accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)

import pandas as pd
import matplotlib.pyplot as plt

# Load the dataset
data = pd.read_csv("TARP.csv")

# Convert the "Time" column to datetime if needed
data["Time"] = pd.to_datetime(data["Time"])

# Set the "Time" column as the index
data.set_index("Time", inplace=True)

# Plotting
plt.figure(figsize=(12, 6))

# Temperature plot
plt.plot(data["Temperature"], label="Temperature")

# Humidity plot
plt.plot(data["Air humidity (%)"], label="Humidity")

# Moisture plot
plt.plot(data["Soil Moisture"], label="Moisture")

plt.title("Temperature, Humidity, and Moisture Trends Over Time")
plt.xlabel("Time")
plt.ylabel("Values")
plt.legend()
plt.grid(True)
plt.show()

