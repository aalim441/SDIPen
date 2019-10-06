# mfc 를 이용한 그림판 새로 만들기 추가 버젼

# 이전 버젼은 제 깃허브 Color_pen 참조하시길 바랍니다.

# 이번시간에 소개할 프로그램은 mfc를 이용하여 펜을 만들어 색깔과 펜의 굵기 그리고 새창을 만들었을때
# 이전에 넣었던 것이 사라지는 것입니다.

# 처음 CLine.h에 들어갑니다.
![image](https://user-images.githubusercontent.com/54826097/66265939-43477280-e859-11e9-9a3a-e274fdc6e221.png)
## 이런식으로 안되어있을텐데 여기서 추가한 점은 int s를 받아서 사이즈를 설정해주었으며
## DECLARE_SERIAL(CLine);가 추가되었습니다. 또한 아무것도 넣지않은 기본 생성자가 있으며
## Draw 에도 10 대신 size가 들어가게 되었습니다. 
## 또한 virtual void Serialize(CArchive& ar);가 추가되어서 다른 곳에서 넘겨받게 됩니다.

![image](https://user-images.githubusercontent.com/54826097/66266003-05971980-e85a-11e9-877e-b8fb07d4d208.png)
## 이 부분은 CLine.cpp인데 저장/불러오기를 할때 쓰입니다.

![image](https://user-images.githubusercontent.com/54826097/66266016-22cbe800-e85a-11e9-8977-6e0b23ae04aa.png)
## 그리고 위와 같이 크기를 집어 넣어 줄수 있게 만듭니다.

![image](https://user-images.githubusercontent.com/54826097/66266044-72121880-e85a-11e9-880b-499dca33b148.png)
## 위와 같이 view.cpp을 만들어 주면 되는데요 이전에 올린 점과 다른점은 size를 따로 외부에 만들어 주었습니다. 저는 기본을 5로 했습니다.

## 또한 전에는 CLine을 만들어 줄때 pnt, point, col 만 만들어서 썻다면 이젠는 size도 같이 넣어 준다는점 잊지마세요

## 그 밑에 onsize들은 제가 위에서 만들어준크기를 집어넣게 하였을 때 이벤트처리기 추가를 했을 때 만들어 집니다. 
## 크기는 원하는 대로 적으시면 됩니다.

![image](https://user-images.githubusercontent.com/54826097/66266086-14320080-e85b-11e9-9d2f-b3a643944ffc.png)
## 이부분은 Doc.cpp에 있는 곳인데 처음에는 거의 비어있습니다. 거기다가 제가 만들어 놓은 것처럼 
```c++
  int n = m_oa.GetSize();

   for (int i = 0; i < n; i++)
      delete m_oa[i];

   m_oa.RemoveAll();
```
## 를 넣어 주시면 되겠습니다.
![image](https://user-images.githubusercontent.com/54826097/66266100-63783100-e85b-11e9-8ee9-5083fee733ab.png)
## 그 바로 밑에 보시면 Serialize 가 보이시면서 뭔가 적혀져 있을텐데 다 지워서 위에처럼 만들어 주시면 됩니다.

![image](https://user-images.githubusercontent.com/54826097/66266168-3aa46b80-e85c-11e9-9ed6-511b26b2a188.png)
## 이렇게 하신다면 이렇게 될겁니다. 일단 펜크기가 바뀌는 사진입니다.

![image](https://user-images.githubusercontent.com/54826097/66266187-822af780-e85c-11e9-8023-e21544c42b29.png)
## 이건 색깔을 변경하는 기능입니다.

![image](https://user-images.githubusercontent.com/54826097/66266223-bc949480-e85c-11e9-8e71-d9c47898eb2e.png)
## 이부분을 눌러서 새로운 파일이 열리는 기능입니다.

![image](https://user-images.githubusercontent.com/54826097/66266257-2a40c080-e85d-11e9-8fd6-59045c022231.png)
# 감사합니다.