SELECT Course_Id, Course_Name FROM Course, Department dt WHERE Course.Department_Id = dt.Department_Id 
AND LOWER(dt.Hod_Username) = 'mohin@gmail.com'

select * from Department


SELECT COUNT(*) FROM Course, Department dt WHERE dt.Department_Id = Course.Department_Id AND LOWER(Course_Name) = @cname AND Department_Id =





delete from Course where Department_Id is null

select * from Course

insert into Course (Course_Name, Department_Id) 
values ('ivankshu', (SELECT top 1 Department_Id FROM Department WHERE Hod_Username = 'mohin@gmail.com' ));

SELECT COUNT(*) FROM Course, Department dt WHERE dt.Department_Id = Course.Department_Id AND LOWER(Course_Name) = 'mca5' AND Hod_Username = 'mohin@gmail.com'


select sub.Subject_Id, sub.Subject_Name, CONCAT(Class.year, '_', Class.semister) as Year_Semester, Course_Name as CourseName, Department_Name as DepartmentName, Faculty_Name as FacultyName from Subject sub, Class, Course, Department dt, Faculty ft where sub.Class_Id = Class.Class_Id and Course.Department_Id = dt.Department_Id and dt.Faculty_Id = ft.Faculty_Id

select * from Subject


select sub.Subject_Id, sub.Subject_Name, CONCAT(Class.year, '-', Class.semister) as Year_Semester , Course_Name as CourseName
from Subject sub, Class, Course
where sub.Class_Id = Class.Class_Id and Class.Course_Id = Course.Course_Id and Course.Course_Id = '100003';

select * from Department where Hod_Username = 'mohin@gmail.com'

select * from Course

select sub.Subject_Id, sub.Subject_Name, CONCAT(Class.year, '-', Class.semister) as Year_Semester , Course_Name as CourseName from Subject sub, Class, Course, Department where sub.Class_Id = Class.Class_Id and Class.Course_Id = Course.Course_Id and Course.Department_Id = Department.Department_Id and Department.Hod_Username = 'mohin@gmail.com'

select sub.Subject_Id, sub.Subject_Name, sub.Elective_Type as E_type, CONCAT(Class.year, '-', Class.semister) as Year_Semester , 
Course_Name as CourseName from Subject sub, Class, Course 
where sub.Class_Id = Class.Class_Id and Class.Course_Id = Course.Course_Id and Course.Course_Id = '100003';

select sub.Subject_Id, sub.Subject_Name, sub.Elective_Type as E_type, CONCAT(Class.year, '-', Class.semister) as Year_Semester , 
Course_Name as CourseName from Subject sub, Class, Course, Department where sub.Class_Id = Class.Class_Id 
and Class.Course_Id = Course.Course_Id 
and Course.Department_Id = Department.Department_Id and Department.Hod_Username = 'mohin@gmail.com'

select * from Course where Department_Id='10011'

select * from Teacher

update Teacher set Password='1' 
insert into Teacher values()