Select status, owner from(select Email, Password, '1' as status, Class_Id as owner from student union all 
Select Email, Password, '2' as status, '' as owner from Teacher union all  
Select Username as Email, Password, '3' as status, '' as owner from Admin union all 
Select Hod_Username as Email, Hod_Password as Password,  '4' as status, Department_Id as owner from Department) as dt where lower(dt.Email) = 'mohin@gmail.com' and dt.Password = '123456'; 
