from apiclient import discovery
from httplib2 import Http
from oauth2client import file, client, tools
import os
import io
from apiclient.http import MediaIoBaseDownload

SCOPES = 'https://www.googleapis.com/auth/drive'
CLIENT_SECRET = 'client_secret.json'
store = file.Storage('storage.json')
creds = store.get()
if not creds or creds.invalid:
    flow = client.flow_from_clientsecrets(CLIENT_SECRET, SCOPES)
    creds = tools.run(flow, store)
DRIVE = discovery.build('drive', 'v2', http=creds.authorize(Http()))

def downloadfile():
    #SERVICE = discovery.build('drive', 'v2', http=creds.authorize(Http()))
    files = DRIVE.files().list(q="mimeType='text/plain'",orderBy = "modifiedDate desc,title",
                                            spaces='drive',
                                            pageToken=None).execute().get('items',[])
    #files = SERVICE.files().list('modifiedTime').execute().get('items',[])

    print ("Number of files = " + str(len(files)))
    for f in files:
        print f['title'], f['mimeType'], f['downloadUrl'], f['id'],
        print ' '
    if len(files) > 0:
        print files[0]['title'], files[0]['mimeType'], files[0]['downloadUrl'], files[0]['id'],
        fileid = files[0]['id']
        MIMETYPE = 'text/plain'
        res, data = DRIVE._http.request(files[0]['downloadUrl'])
        if data:
            filename = files[0]['title']
            fn = '%s_downloaded.gcode' % os.path.splitext(filename)[0]
            with open(fn, 'wb') as fh:
                fh.write(data)
            print('Downloaded "%s" (%s) (%s)' % (fn, MIMETYPE, fileid))
            return fn, fileid

def deletefile(fileid):
    files = DRIVE.files().delete(fileId=fileid).execute()
    #print ("After deletion num of files: " + str(files.len))
    files = DRIVE.files().list(q="mimeType='text/plain'",orderBy = "modifiedDate desc,title",
                                            spaces='drive',
                                            pageToken=None).execute().get('items',[])
    #files = SERVICE.files().list('modifiedTime').execute().get('items',[])

    print ("Number of files after deletion = " + str(len(files)))
'''
    for f in files:
        print f['title'], f['mimeType'], f['downloadUrl'],
        print ' '
    if len(files) > 0:
        print files[0]['title'], files[0]['mimeType'], files[0]['downloadUrl'],
        MIMETYPE = 'text/plain'
        res, data = DRIVE._http.request(files[0]['downloadUrl'])
        if data:
            filename = files[0]['title']
            fn = '%s_downloaded.gcode' % os.path.splitext(filename)[0]
            with open(fn, 'wb') as fh:
                fh.write(data)
            print('Downloaded "%s" (%s)' % (fn, MIMETYPE))
            return fn
        '''