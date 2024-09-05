create table TEAM(TEAM_NO varchar(50) primary key, TEAM_NAME varchar(50), CITY varchar(50));

create table PLAYER(P_ID varchar(50) primary key, P_NAME varchar(50), POSITION varchar(50), HEIGHT varchar(50), TEAM_NO varchar(50), foreign key(TEAM_NO) references TEAM(TEAM_NO), WEIGHT varchar(50));

create table GAME(G_ID varchar(50) primary key, HOME_TEAM varchar(50), foreign key(HOME_TEAM) references TEAM(TEAM_NO), AWAY_TEAM varchar(50), foreign key(AWAY_TEAM) references TEAM(TEAM_NO), CITY varchar(50));

create table GAMESTAT(P_ID varchar(50), foreign key(P_ID) references PLAYER(P_ID), G_ID varchar(50), foreign key(G_ID) references GAME(G_ID), POINTS int);


insert into TEAM(TEAM_NO, TEAM_NAME, CITY) values('T001', 'AAA', 'Kolkata'), ('T002', 'BBB', 'Delhi'), ('T003', 'CCC', 'Mumbai'), ('T004', 'DDD', 'Kerala'), ('T005', 'EEE', 'Agra');
select * from TEAM;

insert into PLAYER(P_ID, P_NAME, POSITION, HEIGHT, WEIGHT, TEAM_NO) values('P001', 'Ritesh Kumar Yadav', 'Guard', 150, 60, 'T001'), ('P002', 'Ashutosh Ghosh', 'Center', 151, 61, 'T001'), ('P003', 'Priya Kumar', 'Forward', 152, 62, 'T001'), ('P004', 'Rima Kumar', 'Guard', 153, 63, 'T002'), ('P005', 'Trina Yadav', 'Center', 154, 64, 'T002'), ('P006', 'Faizam Sett', 'Forward', 155, 65, 'T002'), ('P007', 'Purna Tumo', 'Guard', 156, 66, 'T003'), ('P008', 'Thomas Andrew', 'Center', 157, 67, 'T003'), ('P009', 'Clayton Danie', 'Forward', 158, 68, 'T003'), ('P010', 'Flora Wingrave', 'Guard', 159, 69, 'T004'), ('P011', 'Miles Wingrave', 'Center', 160, 70, 'T004'), ('P012', 'Hannah Grosse', 'Forward', 161, 71, 'T004'), ('P013', 'Owen Grosse', 'Guard', 162, 72, 'T005'), ('P014', 'Jamie Kumar', 'Center', 163, 73, 'T005'), ('P015', 'Charlotte Wingrave', 'Forward', 164, 74, 'T005');
select * from PLAYER;

insert into GAME(G_ID, HOME_TEAM, AWAY_TEAM, CITY) values('G001', 'T001', 'T002', 'Kolkata'), ('G002', 'T002', 'T003', 'Delhi'), ('G003', 'T003', 'T004', 'Mumbai'), ('G004', 'T004', 'T005', 'Kerala'), ('G005', 'T005', 'T001', 'Agra'), ('G006', 'T005', 'T002', 'Kolkata');
select * from GAME;

insert into GAMESTAT(P_ID, G_ID, POINTS) values('P001', 'G001', 1), ('P002', 'G005', 2), ('P003', 'G001', 3), ('P004', 'G002', 4), ('P005', 'G006', 5), ('P006', 'G006', 6), ('P007', 'G003', 7), ('P008', 'G003', 8), ('P009', 'G003', 9), ('P010', 'G004', 10), ('P011', 'G004', 11), ('P012', 'G004', 12), ('P013', 'G005', 13), ('P014', 'G005', 14), ('P015', 'G005', 15);
select * from GAMESTAT;

#Find distinct names of players who play in the 'Guard' position and have name containing the substring #'Kumar'
select distinct P_NAME from PLAYER where POSITION='Guard' and P_NAME like '%Kumar%';

#List out the distinct cities that have more thsn one team playing there.
select distinct city from GAME group by(city) having count(*)>1;

