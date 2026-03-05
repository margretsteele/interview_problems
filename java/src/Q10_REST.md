## Q10 — REST API Design

| # | Action | Method | Path | Status Code |
|---|--------|--------|------|-------------|
| 1 | Get all tasks for a user | GET | /users/tasks/{user_id} | 200 |
| 2 | Create a new task | POST | /users/tasks | 201 |
| 3 | Mark a specific task as complete | PUT | /users/tasks/{id} | 204 |
| 4 | Delete a task | DELETE | /users/tasks/{id} | 204 |
| 5 | Get all tasks that are overdue | GET | /users/tasks/overdue | 200 |
