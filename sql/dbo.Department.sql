CREATE TABLE Department (
    Department_Id   INT  NOT NULL PRIMARY KEY IDENTITY,
    Department_Name VARCHAR (MAX) NULL,
    Hod_Name        VARCHAR (MAX) NULL,
    Hod_Username    VARCHAR (MAX) NULL,
    Hod_Password    VARCHAR (MAX) NULL,
    Faculty_Id      INT NULL,
    CONSTRAINT FK_Department_ToTable FOREIGN KEY (Faculty_Id) REFERENCES Faculty (Faculty_Id) ON DELETE CASCADE
);

