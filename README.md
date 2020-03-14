# HTCondor 101

An introduction to running applications on the University of Liverpool's [HTCondor pool](http://condor.liv.ac.uk/). As an example problem, we will estimate pi using the Monte Carlo method.

In this repository, we will walk through:

* Running C++ applications
* Running Python applications
* Using the Condortools module to programmatically run applications

The structure of each directory is as follows

```
.
|- Implementation of Monte Carlo estimation in the respective language
|- Job description
|- Folder (job) which holds outputs from the job (data outputs, log files, etc.)
|- README.md file containing instructions how to execute the application on Condor
```

## Condortools
Condortools is a Python module that allows users to programmatically interact with the University of Liverpool's HTCondor pool.

## Authors
* Matthew Carter - [mjcarter.co](http://mjcarter.co/)