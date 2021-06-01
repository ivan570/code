select * from student

insert into Student values ('500003', '1', '1@gmail.com', 'Vaghani Ivankshu');

select * from Class

select Class_Id, CONCAT(Year, '-', Semister) as Year_Semister from Class where Course_Id=''

select Student_Id, Student_Name, Email from Student where Class_Id = ''

select * from Department