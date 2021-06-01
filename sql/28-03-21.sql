select Email, Password, '1' as status, dt.Department_Id as owner 
from student, Class, Course, Department as dt where Student.Class_Id = Class.Class_Id and 
                 Class.Course_Id = Course.Course_Id and Course.Department_Id = dt.Department_Id union all 
                 Select Email, Password, '2' as status, '' as owner from Teacher union all    
                 Select Username as Email, Password, '3' as status, '' as owner from Admin union all   
                Select Hod_Username as Email, Hod_Password as Password,  '4' as status, Department_Id 
                 as owner from Department

select * from Department where Department_Id='10012'
select * from Student as stu where stu.Class_Id in (select Class_Id from Class where Course_Id in (select Course_Id from Course where Department_Id='10012'))

select Max(Department_Id) as max_value from Department

select * from Department