# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY addTwoInts.c .
# Compile the C program
RUN gcc -o addTwoInts addTwoInts.c
# Set the command to run when the container starts
CMD ["./addTwoInts"]