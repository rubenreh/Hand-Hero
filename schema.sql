
-- Author: Ruben Rehal

CREATE TABLE UserProgress (
  user_id INT PRIMARY KEY AUTO_INCREMENT,
  username VARCHAR(50),
  improvement_percent DECIMAL(5, 2),
  session_date DATE
);

INSERT INTO UserProgress (username, improvement_percent, session_date)
VALUES ('jane.doe', 38.75, '2025-05-01');
