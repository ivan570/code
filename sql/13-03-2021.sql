
select * from Teacher;
select * from Department;
insert into Teacher (Email, Password, Teacher_Name) value (,,,);

update Teacher set Teacher_Name = 'ivankshu;vaghani'

select Teacher_Id, Email, Teacher_Name as Name from Teacher

select Teacher_Id, Email, (SELECT top 1 value FROM STRING_SPLIT(Teacher_Name, ';') order by value) as fname, 
(SELECT top 1 value FROM STRING_SPLIT(Teacher_Name, ';') order by value DESC) as lname from Teacher

insert into Teacher (Email, Password, Teacher_Name) value ('immyvavvy@gmail.com', '18497700', 'ivankshu;vaghani')