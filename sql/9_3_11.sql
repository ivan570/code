select Course_Id, Course_Name from Course where Department_Id = '10012';

Select * from Class;

select CONCAT(year, '_', semister) from class; 

select *  from Department where Department_Id= 10012;

select * from Subject;

insert into Subject (Class_Id , Subject_Name, Elective_Type) values ();

Select * from Teacher;

insert into Teacher values ('ivankshu@gmail.com', 'Imv@1713', 'ivankshu');

select * from Teacher_Subject;

insert into Teacher_Subject values ('1', '1', 'false');

update Teacher_Subject set Approval = 'true' where Subject_Id='1'

insert into Subject values(500003, '.NET', 'false');

select sub.Subject_Id, sub.Subject_Name, CONCAT(Class.year, '_', Class.semister) as Year_Semester,
Course_Name, Department_Name, Faculty_Name 
from Teacher_Subject ts, 
Subject sub, Class, Course, Department dt, Faculty ft
where ts.Subject_Id = sub.Subject_Id and sub.Class_Id = Class.Class_Id and Course.Department_Id = dt.Department_Id
and dt.Faculty_Id = ft.Faculty_Id and Teacher_Id = 1 and ts.Approval = 'true';


select count(*) from Subject where lower(Subject_Name)='math' and Class_Id='1008';

select * from Subject;