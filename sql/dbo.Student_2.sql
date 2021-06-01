CREATE TABLE Student (
    Student_Id   BIGINT  NOT NULL PRIMARY KEY IDENTITY,
    Class_Id     INT  NULL,
    Password     VARCHAR (MAX) NULL,
    Email        VARCHAR (MAX) NULL,
    Username     VARCHAR (MAX) NULL,
    Student_Name VARCHAR (MAX) NULL,
    PRIMARY KEY CLUSTERED (Student_Id ASC),
    CONSTRAINT FK_Student_ToTable FOREIGN KEY (Class_Id) REFERENCES Class (Class_Id) ON DELETE CASCADE
);

