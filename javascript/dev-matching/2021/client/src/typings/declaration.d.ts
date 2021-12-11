declare module "@src/*";

declare global {
  interface React {
    useState<T>(val): [T, (val: T) => void];
    useEffect(): any;
  }
}
