CREATE TABLE Class (
    Class_Id  INT NOT NULL PRIMARY KEY IDENTITY,
    Course_Id INT NULL,
    Year      TINYINT      NULL,
    Semister  TINYINT      NULL,
    CONSTRAINT FK_Class_ToTable FOREIGN KEY (Course_Id) REFERENCES Course (Course_Id) ON DELETE CASCADE
);

