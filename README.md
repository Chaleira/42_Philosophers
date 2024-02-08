# 42 Philosophers

Welcome to the 42 Philosophers project repository! This project is part of the 42 school curriculum and focuses on solving the dining philosophers problem using threads and synchronization techniques.

## Introduction

The dining philosophers problem is a classic synchronization problem in computer science, where a group of philosophers sit around a table with a bowl of spaghetti. Each philosopher must alternate between thinking and eating, but there are only a limited number of forks (equal to the number of philosophers) placed between them. To eat, a philosopher must pick up both forks adjacent to them. The challenge is to design a solution that prevents deadlock and starvation, where philosophers might starve if they are unable to acquire the necessary forks.

## Features

- Implementation of the dining philosophers problem
- Use of threads and synchronization primitives (mutex, semaphore, etc.)
- Preventing deadlock and starvation
- Visualization of the dining philosophers scenario
