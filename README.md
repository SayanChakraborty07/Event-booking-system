#Introduction

This project is a console-based application developed in C++ that allows users to register, log in, view available events, book seats for events, and cancel bookings. It provides a simple, menu-driven interface that facilitates efficient event management and seat tracking.


#Objective

The main goal of this project is to create a system where users can easily:

Register their accounts securely.
View details of upcoming events.
Book seats for their desired events.
Cancel their event bookings if needed.
It aims to simulate a basic real-world event management system with essential features.


#Features

User Registration and Login: Users can securely register and log in using their email, password, username, and mobile number.
Password Protection: Password input is masked for security.

Event Display: View all available events with details like date, venue, organizer, guest, and available seats.
Event Booking: Book a seat for any available event, automatically reducing available seats.
Booking Cancellation: Cancel an existing booking, with the system updating seat availability.
Data Management: Use of maps and vectors to efficiently manage user information and event bookings.


#Technologies Used

Programming Language: C++

Libraries:

<iostream> for input/output operations
<string>, <vector>, <map>, <tuple> for data management.
<conio.h> for handling password input masking.


#How It Works

Users can register by providing an email, username, password, and mobile number.
After registration, users can log in using their credentials.
Logged-in users can:
View all available events.
Book seats for an event.
Cancel their existing bookings.
The system dynamically updates the number of available seats based on bookings and cancellations.


#Use Cases

Managing registrations and bookings for college or small-scale community events.
Educational projects to demonstrate object-oriented programming and file-less data handling.
A base prototype for more advanced event booking platforms.


#Conclusion

This Event Booking and Management System successfully demonstrates core concepts of C++ such as classes, inheritance, vectors, maps, and user input handling. It offers a basic but functional model for real-world event management applications and can be expanded with features like event creation by organizers, booking history tracking, or database connectivity for larger deployments.
