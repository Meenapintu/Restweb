INSERT INTO ulogin.userlogin(username, name, email, mobile, password, "DOB", gender)
VALUES (?, ?, ?, ?, ?, ?, ?);

SELECT username, name, email, mobile, password, "DOB", gender
FROM ulogin.userlogin;

DELETE FROM ulogin.userlogin
WHERE <condition>;


UPDATE ulogin.userlogin
SET username=?, name=?, email=?, mobile=?, password=?, "DOB"=?, gender
WHERE <condition>;
