insert into Attendance_10011(Student_Id, Teacher_Subject_Id, isPresent, LectureDate, 
StartTime, EndTime) values ('100000001', (select OTP.Teacher_Subject_Id, 
DATEDIFF(MILLISECOND, DateTime, SYSDATETIME()) from OTP where OTP.OTP='1600324' and 
DATEDIFF(MILLISECOND, DateTime, SYSDATETIME()) <= 30000), 'true', '2015-10-10', 
'10:45', '11:45');

select * from OTP

update OTP set DateTime = SYSDATETIMEOFFSET()

select CAST(GETDATE() AS TIME)

insert into Attendance_10018(Student_Id, Teacher_Subject_Id, isPresent, LectureDate, 
Duration) values ((select Student_Id from Student where Email='1@gmail.com'), 
(select OTP.Teacher_Subject_Id from OTP where OTP.OTP='1600324'
and DATEDIFF(MILLISECOND, DateTime, SYSDATETIME()) <= 
(select Validity_in_sec * 1000 from OTP where OTP='1600324')), 'true', GETDATE(), 
(select Duration from OTP where OTP = '1600324'))

select * from Attendance_10018

delete from Attendance_10018 where Teacher_Subject_Id is null

select * from OTP
update OTP set Validity_in_sec='30'
update OTP set Duration='01:20'

select Student_Id from Student where Email=''
