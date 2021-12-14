export interface VirtualDOMTreeType {
  tagName: string;
  props: {
    [key: string]: string;
  };
  event: {
    [key: string]: string;
  };
  dirty?: boolean;
  childNode?: VirtualDOMTreeType[];
}

// 참고: http://blog.drakejin.me/React-VirtualDOM-And-Repaint-Reflow/
