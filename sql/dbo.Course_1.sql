CREATE TABLE Course (
    Course_Id     INT  NOT NULL PRIMARY KEY IDENTITY,
    Department_Id INT  NULL,
    Course_Name   VARCHAR (MAX) NULL,
    CONSTRAINT FK_Course_ToTable FOREIGN KEY (Department_Id) REFERENCES Department (Department_Id) ON DELETE CASCADE
);

