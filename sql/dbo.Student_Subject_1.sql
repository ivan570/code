CREATE TABLE Student_Subject (
    Student_Subject_Id BIGINT NOT NULL PRIMARY KEY IDENTITY,
    Student_Id         BIGINT NULL,
    Subject_Id         INT NULL,
    CONSTRAINT FK_Student_Subject_ToTable_Student_Id FOREIGN KEY (Student_Id) REFERENCES Student (Student_Id),
    CONSTRAINT FK_Student_Subject_ToTable_Subject_Id FOREIGN KEY (Subject_Id) REFERENCES Subject (Subject_Id)
);

