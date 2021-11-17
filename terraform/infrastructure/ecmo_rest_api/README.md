
## textbook - chapters

### Using windows powershell

PUT or POST a textbook chapter
```
C:\Windows\System32\curl.exe -v -X 'PUT' -H 'Content-Type:application/json' -d '{\"id\": \"00\", \"chapter_number\": \"0\", \"chapter_title\": \"preface\"}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters

C:\Windows\System32\curl.exe -v -X 'PUT' -H 'Content-Type:application/json' -d '{\"id\": \"01\", \"chapter_number\": \"1\", \"chapter_title\": \"introduction\"}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters

C:\Windows\System32\curl.exe -v -X 'POST' -H 'Content-Type:application/json' -d '{\"id\": \"01\", \"chapter_number\": \"0\", \"chapter_title\": \"preface\"}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters
```

GET all textbook chapters
```
C:\Windows\System32\curl.exe -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters
```

GET textbook chapter by id
```
C:\Windows\System32\curl.exe -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters/00
```
DELETE a textbook chapter by id
```
C:\Windows\System32\curl.exe -v -X 'DELETE' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters/01
```

### Using curl on linux

PUT or POST a textbook chapter
```
curl -v -X 'PUT' -H 'Content-Type:application/json' -d '{\"id\": \"00\", \"chapter_number\": \"0\", \"chapter_title\": \"preface\"}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters
curl -v -X 'PUT' -H 'Content-Type:application/json' -d '{\"id\": \"01\", \"chapter_number\": \"1\", \"chapter_title\": \"introduction\"}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters
```

GET all textbook chapters
```
curl -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters
```

GET a textbook chapter by id
```
curl -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters/00
```

POST a textbook chapter
```
curl -v -X 'POST' -H 'Content-Type:application/json' -d '{\"id\": \"01\", \"chapter_number\": \"0\", \"chapter_title\": \"preface\"}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters
```

DELETE a textbook chapter
```
curl -v -X 'DELETE' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/chapters/01
```

## textbook - pages
### Using windows powershell

PUT textbook page
```
C:\Windows\System32\curl.exe -v -X 'PUT' -H 'Content-Type:application/json' -d '{\"id\": \"01\", \"chapter_number\": \"0\", \"chapter_title\": \"preface\", \"header_content\": \"dummy_header\", \"subheader_content\": \"dummy_subheader\", \"left_content\": \"dummy_content\", \"right_content\": \"dummy_content\", \"img_src_content_top_right\": \"\", \"img_src_content_bottom_right\": \"\", \"img_src_content_top_left\": \"\", \"img_src_content_bottom_left\": \"\", \"img_header_content_top_right\": \"\", \"img_header_content_bottom_right\": \"\", \"img_header_content_top_left\": \"\", \"img_header_content_bottom_left\": \"\", \"config_left_width\": \"more_dummy_config\", \"config_right_width\": \"dummy_config\", \"config_mirrored_view\": false, \"config_completed\": true}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages
```

GET all textbook pages
```
C:\Windows\System32\curl.exe -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages
```

GET textbook page by id
```
C:\Windows\System32\curl.exe -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages/01
```

POST textbook page by ids
```
C:\Windows\System32\curl.exe -v -X 'POST' -H 'Content-Type:application/json' -d '{\"id\": \"01\", \"chapter_number\": \"0\", \"chapter_title\": \"preface\", \"header_content\": \"dummy_header\", \"subheader_content\": \"dummy_subheader\", \"left_content\": \"dummy_content\", \"right_content\": \"dummy_content\", \"img_src_content_top_right\": \"\", \"img_src_content_bottom_right\": \"\", \"img_src_content_top_left\": \"\", \"img_src_content_bottom_left\": \"\", \"img_header_content_top_right\": \"\", \"img_header_content_bottom_right\": \"\", \"img_header_content_top_left\": \"\", \"img_header_content_bottom_left\": \"\", \"config_left_width\": \"more_dummy_config\", \"config_right_width\": \"dummy_config\", \"config_mirrored_view\": false, \"config_completed\": true}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages
```

DELETE textbook page by id
```
C:\Windows\System32\curl.exe -v -X 'DELETE' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages/01
```

### Using curl on linux

PUT textbook page
```
curl -v -X 'PUT' -H 'Content-Type:application/json' -d '{\"id\": \"01\", \"chapter_number\": \"0\", \"chapter_title\": \"preface\", \"header_content\": \"dummy_header\", \"subheader_content\": \"dummy_subheader\", \"left_content\": \"dummy_content\", \"right_content\": \"dummy_content\", \"img_src_content_top_right\": \"\", \"img_src_content_bottom_right\": \"\", \"img_src_content_top_left\": \"\", \"img_src_content_bottom_left\": \"\", \"img_header_content_top_right\": \"\", \"img_header_content_bottom_right\": \"\", \"img_header_content_top_left\": \"\", \"img_header_content_bottom_left\": \"\", \"config_left_width\": \"more_dummy_config\", \"config_right_width\": \"dummy_config\", \"config_mirrored_view\": false, \"config_completed\": true}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages
```

GET all textbook pages
```
curl -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages
```

GET textbook page by id
```
curl -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages/01
```

POST textbook page by ids
```
curl -v -X 'POST' -H 'Content-Type:application/json' -d '{\"id\": \"01\", \"chapter_number\": \"0\", \"chapter_title\": \"preface\", \"header_content\": \"dummy_header\", \"subheader_content\": \"dummy_subheader\", \"left_content\": \"dummy_content\", \"right_content\": \"dummy_content\", \"img_src_content_top_right\": \"\", \"img_src_content_bottom_right\": \"\", \"img_src_content_top_left\": \"\", \"img_src_content_bottom_left\": \"\", \"img_header_content_top_right\": \"\", \"img_header_content_bottom_right\": \"\", \"img_header_content_top_left\": \"\", \"img_header_content_bottom_left\": \"\", \"config_left_width\": \"more_dummy_config\", \"config_right_width\": \"dummy_config\", \"config_mirrored_view\": false, \"config_completed\": true}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages
```

DELETE textbook page by id
```
curl-v -X 'DELETE' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/textbook/pages/01
```

## scenario
### Using windows powershell

NOTE: THERE IS NO POST FUNCTION FOR SCENARIO

PUT scenario by id
```
C:\Windows\System32\curl.exe -v -X 'PUT' -H 'Content-Type:application/json' -d '{\"id\": \"00\"}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/scenario
```

GET all scenarios
```
C:\Windows\System32\curl.exe -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/scenario
```

GET scenario by id
```
C:\Windows\System32\curl.exe -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/scenario/00
```

DELETE scenario by id
```
C:\Windows\System32\curl.exe -v -X 'DELETE' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/scenario/00
```

### Using curl on linux

NOTE: THERE IS NO POST FUNCTION FOR SCENARIO

PUT scenario by id
```
curl -v -X 'PUT' -H 'Content-Type:application/json' -d '{\"id\": \"00\"}' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/scenario
```

GET all scenarios
```
curl -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/scenario
```

GET scenario by id
```
curl -v -X 'GET' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/scenario/00
```
DELETE scenario by id
```
curl -v -X 'DELETE' -H 'Content-Type:application/json' https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com/scenario/00
```
