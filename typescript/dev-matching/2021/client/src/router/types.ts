export interface RouteType {
  path: string;
  view: () => string;
  queryString: boolean;
}

export const pages: RouteType[] = [
  {
    path: "/",
    view: (): string => {
      const component = "";
      return component;
    },
    queryString: false,
  },
  {
    path: "products",
    view: (): string => {
      const component = "";
      return component;
    },
    queryString: true,
  },
  {
    path: "cart",
    view: (): string => {
      const component = "";
      return component;
    },
    queryString: false,
  },
];

export interface PageType {
  route: RouteType;
  matchPage: boolean;
  props?: any;
}
