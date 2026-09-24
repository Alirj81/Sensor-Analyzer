# Streaming Sensor Analyzer

## About This Task

This project is part of my weekly C programming practice.

The task is to build a program that reads sensor data from a text file, validates each record, and calculates statistics for every device.

Example input:

```text
2026-09-13T08:14:31;MOTOR-03;72.4;OK
2026-09-13T08:14:32;PUMP-01;91.7;WARNING
2026-09-13T08:14:33;MOTOR-03;105.2;CRITICAL
```

The program should calculate information such as:

* number of valid readings
* average value
* minimum value
* maximum value
* warning count
* critical count
* malformed record count

## My Goal

The purpose of this task is not only to get the correct output, but to improve my understanding of practical C programming.

I am using this exercise to practice:

* reading files with `fgets()`
* parsing structured text
* validating user/file input
* using `struct`
* working with strings
* converting strings to numeric values safely
* separating a program into smaller functions
* maintaining statistics while processing a data stream
* handling malformed input without crashing
* thinking about memory usage and ownership
* designing programs that can scale to large files

A major goal is also to avoid simply storing every input record. Instead, I am learning how to process data as it arrives and keep only the information required for the final statistics.

## Progress

The accompanying Jupyter notebook documents my development process, including:

* my initial approach
* mistakes I encountered
* changes to the program architecture
* parsing and validation techniques
* per-device statistics design
* malformed input handling
* thoughts about processing very large files

This repository is intended to show both the implementation and my learning process while becoming more comfortable with C and general software engineering practices.
