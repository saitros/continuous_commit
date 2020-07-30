```
> MarkDown preview 오류 수정 후 수정
```


# Commit message Convention

Git repo 를 사용하면서 다양한 message 가 많고, 사실 필자 또한 본인만 알아보기위한 Commit Message 를 작성했었다.

하지만 Git을 협업으로 사용함에 있어서 난잡한 개인적 Commit 은 비효율적이라고 생각되며, 추후 유지보수를 위해서라도 정리가 필요할것 같아 관련된 자료를 찾던 도중 Commit Message Convention 이라는 키워드를 발견하고 관련된 내용을 이번 문서에서 정리하고자 한다.

## About Git commit message

![](https://d33wubrfki0l68.cloudfront.net/ab6c349cef44ee6b617234b4f2574b978ef2fa3e/42749/images/posts/2019-11-01-understanding-semantic-commit-messages-using-git-and-angular/commit-message-format-by-angular.png)

Header 라고 표현되어있는 Commit 의 제목 부분이 주로 Commit 메세지를 남기는 제목부분이고, Body Footer 는 Github 에서 Add an optional extended description 이라고 표현된 내용 부분이다.

필자는 주로 Header 부분만 작성하여 Commit을 하는데 Commit Convention에 따르면 Header는 3가지 요소로 구성되어있다.

### Header

####Type
  $\rightarrow$ 어떤 종류의 Commit 인지 알려주는 요소

| Type Name | Description|
|:-----------|:------------|
|fix|버그 수정,보완|
|chore|소스코드, 테스트 파일을 제외한 수정|
|perf|성능 개선|
|build|빌드 시스템 수정, 외부 종속 라이브러리 수정|
|docs|문서 수정|
|style|코드 포맷팅, 코드 변경이 없는 경우(인덴트, 세미콜론 등)|
|refactor|코드 리펙토링|
|test|기존 테스트 코드 수정 및 새로운 테스트 코드 추가|
|feat| 새로운 기능 추가|

#### Scope
$\rightarrow$ 필수 x, Type 을 추가 설명하는 용도로 사용.
예시로, fix(parser), fix(tokenizer) 등 명사형으로 괄호 속에 표현되어야한다.

#### Subject
$\rightarrow$ Header의 길이가 50자를 넘지 않는 선에서, 짧은 영문설명, 현재/과거를 따지지 않고 기본형으로 작성한다.

해당 내용은 Git commit 의 man 페이지에도 다음과 같이 서술되어있습니다.


>Though not required, it’s a good idea to begin the commit message with a single short (less than 50 character) line summarizing the change, followed by a blank line and then a more thorough description. The text up to the first blank line in a commit message is treated as the commit title, and that title is used throughout Git. For example, git-format-patch(1) turns a commit into email, and it uses the title on the Subject line and the rest of the commit in the body.

요약하면 50자 이내의 요약문장과 하나의 빈 줄, 그리고 설명문으로 구성하면 좋다.

다음 내용을 참고해서 작성중에 있습니다.
* https://blog.naver.com/PostView.nhn?blogId=duswl0319&logNo=221913439523&parentCategoryNo=&categoryNo=15&viewDate=&isShowPopularPosts=true&from=search
* https://djkeh.github.io/articles/How-to-write-a-git-commit-message-kor/
