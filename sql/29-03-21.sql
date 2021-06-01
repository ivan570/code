select * from OTP

 insert into Attendance_10018(Student_Id, Teacher_Subject_Id, isPresent, LectureDate,  Duration)
 values ((select Student_Id from Student where Email='1@gmail.com'),  
 (select OTP.Teacher_Subject_Id from OTP where OTP.OTP='1600324' and 
 DATEDIFF(MILLISECOND, DateTime, SYSDATETIME()) <=  
 (select Validity_in_sec * 1000 from OTP where OTP='1600324')), 
 'true', GETDATE(),  (select Duration from OTP where OTP = '1600324')) 


 (select OTP.Teacher_Subject_Id from OTP where OTP.OTP='1600324' and 
 DATEDIFF(MILLISECOND, DateTime, SYSDATETIME()) <=  
 (select Validity_in_sec * 1000 from OTP where OTP='1600324'))