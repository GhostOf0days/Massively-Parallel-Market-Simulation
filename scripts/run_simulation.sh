#!/bin/bash

# Set the number of MPI processes
NUM_PROCESSES=4

# Run the market simulation
mpirun -np $NUM_PROCESSES ./market_simulator