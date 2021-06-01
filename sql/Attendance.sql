CREATE TABLE Demo_attendance
(
	Attendance_Id BIGINT NOT NULL PRIMARY KEY IDENTITY, 
    Student_Id BIGINT NULL, 
    Teacher_Subject_Id INT NULL, 
    isPresent BIT NULL,
    LectureDate Date null,
    StartTime TIME NULL,
    EndTime TIME NUll, 
    CONSTRAINT FK_Demo_attendance_ToTable_Teacher_Subject FOREIGN KEY (Teacher_Subject_id) REFERENCES Teacher_Subject(Teacher_Subject_Id), 
    CONSTRAINT FK_Demo_attendance_ToTable_Student_Id FOREIGN KEY (Student_Id) REFERENCES Student(Student_Id)
)
