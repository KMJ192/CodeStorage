export = global;

declare global {
  interface Window {
    increament: () => void;
    decreament: () => void;
    cat: () => void;
  }
}
