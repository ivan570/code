
select * from Teacher_Subject


select * from Subject

select conca



select Subject_Name from Subject, Class, Course, Department where 
Subject.Class_Id = Class.Class_Id 
and Class.Class_Id = Course.Course_Id 
and Course.Department_Id = Department.Department_Id 
and Department.Hod_Username = ''
