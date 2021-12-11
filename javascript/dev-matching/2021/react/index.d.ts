export = React;
export as namespace React;
declare namespace React {
  type Dispatch<T> = (value: T) => void;

  type SetStateAction<T> = T | ((prevState: T) => T);

  function useState<T>(
    initialState: T | (() => T)
  ): [T, Dispatch<SetStateAction<T>>];

  function useState<T = undefined>(): [
    T | undefined,
    Dispatch<SetStateAction<T | undefined>>
  ];
}
