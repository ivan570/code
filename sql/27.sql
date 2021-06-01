select * from Demo_attendance; 
select * from Teacher_Subject;
select * from Student;

insert into Demo_attendance (Student_Id, Teacher_Subject_Id, isPresent, LectureDate, StartTime, EndTime) 
values ('100000001', '11', 'true', ('2015-10-10'), '10:45', '11:45');

select * from OTP

insert into OTP (OTP, DateTime, Teacher_Subject_Id) values ('1600324', SYSDATETIMEOFFSET(), '11')

 

