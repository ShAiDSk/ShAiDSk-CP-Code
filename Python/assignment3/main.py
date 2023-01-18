import gurobipy as gp
from gurobipy import GRB

weeks = [
    "April1", "April2", "April3", "April4", 
    "May1", "May2",  "May3",  "May4", 
    "June1", "June2", "June3", "June4", 
    "July1", "July2", "July3", "July4", 
    "August1", "August2", "August3", "August4", 
    "September1", "September2", "September3", "September4",
    "October1", "October2", "October3", "October4"
    ]

drones = ["Drone1", "Drone2", "Drone3", "Drone4", "Drone5", "Drone6", "Drone7", "Drone8"]


availabilityMatrix = [
#Week 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
     [1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0], # Drone1
     [1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0], # Drone2
     [0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1], # Drone3
     [1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0], # Drone4
     [0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1], # Drone5
     [0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1], # Drone6
     [1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0], # Drone7
     [1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1]  # Drone8
]

availability = {(d, w): availabilityMatrix[j][i]
                for i, w in enumerate(weeks)
                for j, d in enumerate(drones)}


#              Week 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
requirementsList = [6, 4, 7, 5, 6, 6, 5, 5, 6, 6, 8, 7, 7, 8, 7, 7, 6, 6, 7, 8, 8, 7, 6, 8, 6, 5, 6, 6]


requirements = {weeks[i]: w for i, w in enumerate(requirementsList)}



model = gp.Model("Drone Scheduling Exercise 1")
print (model)

# Implement your model here

#adding variables
# drones_used = model.addVars(drones, vtype=GRB.BINARY, name="Drones Used")

