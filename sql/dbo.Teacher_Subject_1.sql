CREATE TABLE Teacher_Subject (
    Teacher_Subject_Id INT NOT NULL PRIMARY KEY IDENTITY,
    Subject_Id         VARCHAR (50) NULL,
    Teacher_Id         VARCHAR (50) NULL,
    CONSTRAINT FK_Teacher_Subject_ToTable_Teacher FOREIGN KEY (Teacher_Id) REFERENCES Teacher (Teacher_Id),
    CONSTRAINT FK_Teacher_Subject_ToTable_Subject FOREIGN KEY (Subject_Id) REFERENCES Subject (Subject_Id)
);