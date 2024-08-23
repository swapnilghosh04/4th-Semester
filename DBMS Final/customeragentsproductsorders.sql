create table Customer(cid varchar(50) primary key, cname varchar(50), c_city varchar(50), discount varchar(50));

create table Agents(aid varchar(50) primary key, aname varchar(50), a_city varchar(50), communication varchar(50));

create table Products(pid varchar(50) primary key, pname varchar(50), p_city varchar(50), quantity varchar(50), price varchar(50));

create table Orders(ord_no varchar(50) primary key, month varchar(50), cid varchar(50), foreign key(cid) references Customer(cid), aid varchar(50), foreign key(aid) references Agents(aid), pid varchar(50), foreign key(pid) references Products(pid), qty varchar(50), total_price varchar(50));


insert into Customer values(1, 'Rajat', 'Kolkata', '5%');
insert into Customer values(2, 'Neel', 'Barasat', '10%');
insert into Customer values(3, 'Priya', 'Kolkata', '15%');
insert into Customer values(4, 'Faizam', 'Howrah', '20%');
insert into Customer values(5, 'Sunil', 'Ranaghat', '25%');
select * from Customer;

insert into Agents values(1, 'Nilam', 'Kolkata', 'Online');
insert into Agents values(2, 'Neeraj', 'Howrah', 'Online');
insert into Agents values(3, 'Nidhi', 'Sodepur', 'Offline');
insert into Agents values(4, 'Pranay', 'Barrackpore', 'Offline');
insert into Agents values(5, 'Sumita', 'Ranaghat', 'Offline');
insert into Agents values(6, 'Anuj', 'Shyamnagar', 'Online');
select * from Agents;

insert into Products values(1, 'Laptop', 'Kolkata', 10, 23000);
insert into Products values(2, 'Microwave', 'Barasat', 20, 23000);
insert into Products values(3, 'Television', 'Barasat', 30, 34000);
insert into Products values(4, 'Refrigerator', 'Howrah', 30, 42000);
insert into Products values(5, 'Tablet', 'Howrah', 40, 44000);
insert into Products values(6, 'Cellphone', 'Howrah', 50, 58000);
select * from Products;

insert into Orders values(1, 'January', 1, 1, 1, 1, 23000);
insert into Orders values(2, 'February', 2, 2, 4, 2, 84000);
insert into Orders values(3, 'March', 1, 3, 2, 1, 23000);
insert into Orders values(4, 'April', 1, 4, 5, 1, 44000);
insert into Orders values(5, 'May', 2, 4, 1, 1, 23000);
insert into Orders values(6, 'June', 3, 4, 1, 1, 23000);
insert into Orders values(7, 'June', 4, 5, 6, 1, 58000);
insert into Orders values(8, 'July', 5, 5, 6, 1, 58000);
select * from Orders;


#Get the name of the agents with a name beginning with the letter 'N' who does not place orders for any product in 'Barasat'.
select aname from Agents where aname like 'N%' and aid in (select aid from Orders where pid not in (select pid from Products where p_city='Barasat'));

