### window.requestAnimationFrame()

- 화면에 새로운 애니메이션을 업데이트할 준비가 될 떄 마다 메서드 호출
- 브라우저에 수행하기를 원하는 애니메이션을 알리고, 다음 repaint가 진행되기 전 해당 애니메이션을 업데이트하는 함수를 호출
  `브라우저가 변화된 화면을 그릴 준비가 되었을때 그려준다.`
- setTimeout 함수와는 다르게 브라우저가 스스로 실행 시점을 조절한다.
- requestAnimationFrame이 1초동안 실행되는 횟수는 브라우저에서 W3C권장사항에 따라 디스플레이 주사율과 일치함
<table>
  <tr>
    <td>60Hz</td>
    <td>60 per's</td>
  </tr>
  <tr>
    <td>144Hz</td>
    <td>144 per's</td>
  </tr>
  <tr>
    <td>240Hz</td>
    <td>240 per's</td>
  </tr>
</table>
- explore와 edge 17v 이하는 페인트 사이클 이전에 requestAnimationFrame 실행을 보장하지 않음
- requestAnmiationFrame은 콜백 리스트의 항목을 정의한느 고유한 요청 id인 long 정수값. 0이 아닌 어떤 랜덤값이다. 이 값으로 <strong>window.cancelAnimationFrame()</strong>에 전달하여 콜백 요청을 취소할 수 있다.

[참고](https://developer.mozilla.org/ko/docs/Web/API/Window/requestAnimationFrame)

### window.cancelAnimationFrame()

- window.requestAnimationFrame()을 호출하여 스케줄된 애니메이션 프레임 요청을 취소함
