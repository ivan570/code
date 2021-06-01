CREATE TABLE Subject (
    Subject_Id    INT  NOT NULL PRIMARY KEY IDENTITY,
    Class_Id      INT  NULL,
    Subject_Name  VARCHAR (MAX) NULL,
    Elective_Type BIT           NULL,
    PRIMARY KEY CLUSTERED (Subject_Id ASC),
    CONSTRAINT FK_Subject_ToTable FOREIGN KEY (Class_Id) REFERENCES Class (Class_Id) ON DELETE CASCADE
);

