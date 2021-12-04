import productList from "../productList";
import coffeeMachineInfo from "../coffeeMachineInfo";
import shoppingBack from "../shoppingBack";

function router() {
  const routePath = location.hash;
  if (routePath === "") {
    productList();
  }
}

window.addEventListener("hashchange", router);

export default router;
