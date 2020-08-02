create temporary table in_progress ( ID INT NOT NULL, project_name VARCHAR(50) NOT NULL );


INSERT INTO in_progress SELECT name as projectName FROM projects Where BeginDate is not NULL and EndDate is NULL;

SELECT COUNT(projectName) FROM in_progress;
