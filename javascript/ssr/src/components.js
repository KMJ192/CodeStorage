import { store } from "./store.js";

export const TodoList = () => `
  <ul>
    ${store.state.todoItems.map(TodoItem).join("")}
  </ul>
`;

export const TodoItem = ({ id, content, activation }) => `
  <li data-id="${id}">
    <input type="checkbox" ${activation ? "checked" : ""} />
    <span ${
      activation ? ' style="text-decoration: line-through;"' : ""
    }>${content}</span>
  </li>
`;
