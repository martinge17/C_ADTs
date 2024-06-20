# Use an official gcc image as a parent image
FROM gcc:latest

# Copy the current directory contents into the container at /usr/src/myapp
COPY . /usr/src/myapp

# Set the working directory in the container
WORKDIR /usr/src/myapp

# Build the C program
#RUN gcc -o myprogram myprogram.c

# Command to run the executable
#CMD ["./myprogram"]
