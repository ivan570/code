select sub.Subject_Id, sub.Subject_Name, CONCAT(Class.year, '_', Class.semister) as Year_Semester,
Course_Name, Department_Name, Faculty_Name 
from Teacher_Subject ts, 
Subject sub, Class, Course, Department dt, Faculty ft
where ts.Subject_Id = sub.Subject_Id and sub.Class_Id = Class.Class_Id and Course.Department_Id = dt.Department_Id
and dt.Faculty_Id = ft.Faculty_Id;