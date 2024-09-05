create table Hotel(hotelno varchar(50) primary key, hotelname varchar(50), city varchar(50), check(city in('KOLKATA', 'DELHI', 'BANGALORE', 'MUMBAI')));

create table Guest(guestno varchar(50) primary key, guestname varchar(50), guest_address varchar(50));

create table Booking(hotelno varchar(50), foreign key(hotelno) references Hotel(hotelno), guestno varchar(50), foreigQuery OK, 0 rows affected (0.02 sec)tno), datefrom date, dateto date, room_no varchar(50));

insert into Hotel(hotelno, hotelname, city) values('H001', 'Hotel Raj', 'KOLKATA'), ('H002', 'Hotel Deluxe', 'DELHI'), ('H003', 'Hotel Comfort',
'BANGALORE'), ('H004', 'Hotel Grand', 'MUMBAI'), ('H005', 'Hotel Sunrise', 'DELHI'), ('H006', 'Hotel Paradise', 'KOLKATA'), ('H007', 'Hotel Elite', 'MUMBAI'), ('H008', 'Hotel Summit', 'BANGALORE'), ('H009', 'Hotel Tranquil', 'DELHI'), ('H010', 'Hotel Vista', 'KOLKATA');
select * from Hotel;

insert into Guest(guestno, guestname, guest_address) values('G001', 'Anil Kapoor', '123 Main St, KOLKATA'), ('G002', 'Neha Sharma', '456 Elm St, DELHI'), ('G003', 'Rajesh Kumar', '789 Maple St, BANGALORE'), ('G004', 'Sunita Singh', '101 Pine St, MUMBAI'), ('G005', 'Vikram Patel', '202 Oak St, DELHI'), ('G006', 'Rita Gupta', '303 Birch St, KOLKATA'), ('G007', 'Amitabh Bachchan', '404 Cedar St, MUMBAI'), ('G008', 'Deepika Padukone', '505 Spruce St, BANGALORE'), ('G009', 'Shilpa Shetty', '606 Fir St, DELHI'), ('G010', 'Katrina Kaif', '707 Redwood St, KOLKATA');
select * from Guest;

insert into Booking(hotelno, guestno, datefrom, dateto, room_no) values('H001', 'G001', '2012-02-27', '2012-02-28', 'R001'), ('H002', 'G006', '2012-03-01', '2012-03-05', 'R002'), ('H003', 'G002', '2012-02-28', '2012-03-02', 'R003'), ('H004', 'G003', '2012-03-03', '2012-03-07', 'R004'), ('H001', 'G004', '2012-03-04', '2012-03-06', 'R005'), ('H005', 'G005', '2012-03-01', '2012-03-05', 'R006'), ('H006', 'G006', '2012-02-25', '2012-02-27', 'R007'), ('H007', 'G007', '2012-02-28', '2012-03-01', 'R008'), ('H008', 'G008', '2012-02-29', '2012-03-03', 'R009'), ('H009', 'G009', '2012-03-06', '2012-03-09', 'R010'), ('H001', 'G010', '2012-03-10', '2012-03-12', 'R005');
select * from Booking;


#Give the names and city of the hotel having no booking from 28th Feb. 2012 to 3rd March 2012.


#Give the Guest details for the guests who booked in Hotel Raj in Kolkata in Room No. R005.
select * from Guest, Booking, Hotel where Guest.guestno=Booking.guestno and Booking.hotelno=H
otel.hotelno and Booking.room_no='R005';
