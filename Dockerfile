# Use an official gcc image as a parent image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /usr/src/cadts

# Copy the current directory contents into the container at /usr/src/myapp
COPY . .

# Build the C program
#RUN gcc -o myprogram myprogram.c

# Command to run the executable
#CMD ["./myprogram"]
