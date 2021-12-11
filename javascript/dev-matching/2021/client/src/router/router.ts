import { routeInfo, Routes, PageTypes } from "./types";

export const navigateTo = (url: string) => {
  history.pushState(null, "", url);
  router();
};

async function router() {
  const mainContainer: Element = document.getElementsByClassName("App")[0];
  const { pathname } = location;

  const routing: PageTypes[] = routeInfo.map((page: Routes) => {
    const result = {
      route: page,
    };
    if (page.path === "/") {
      return {
        ...result,
        isMatch: pathname === page.path,
      };
    }

    if (page.queryString === true) {
      const id = pathname.split("/");
      return {
        ...result,
        isMatch: pathname.indexOf(page.path) >= 0,
        param: {
          id: id[id.length - 1],
        },
      };
    }

    return {
      ...result,
      isMatch: pathname.indexOf(page.path) >= 0,
    };
  });

  let renderPage = routing.find((match) => match.isMatch);

  if (!renderPage) {
    renderPage = {
      route: routeInfo[0],
      isMatch: true,
    };
  }

  renderPage?.route.view(mainContainer, renderPage.param);
}

export default router;
