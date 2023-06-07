# **Implementing Lambda functions:**
# Create AWS Lambda functions to process and transform the incoming IoT data.
# Configure the Lambda functions to listen for IoT Core messages and perform desired operations.
# Transform the data into a suitable format for storage and further processing.


# Import packages
import boto3
import json
import time
from datetime import datetime

# A low-level client representing Amazon Simple Storage Service (S3)
s3 = boto3.resource('s3')

def labmda_handler(event, context): 
    data = json.loads(event['payload'])
    input_str = data['input']
    weight = data['weight']
    timestamp = int(data['timestamp'])
    date_str = datetime.fromtimestamp(timestamp).strftime("%B %d, %Y")
    time_str = datetime.fromtimestamp(timestamp).strftime("%I :%M %p")
    day_of_week_str = datetime.fromtimestamp(timestamp).strftime("%A")
    
    # The filename is constructed using the timestamp obtained from the IoT device. 
    # It incorporates the timestamp in the file name to make it unique and easily identifiable. 
    # the string 'load_cell_data_' is concatenated with the timestamp value obtained from the IoT device, and the extension .json is appended to indicate that the file contains JSON data.
    filename = f'load_cell_data_{timestamp}.json'

    # By using the s3.Object().put() method we can store JSON data in S3 with the specified filename. 
    # The bucket name is the name of the S3 bucket where we store the object. 
    # The filename is the name of the file that will be store in the bucket. 
    # The .put() method stores the object in S3.
    # Body=json.dumps({...}) specifies the body of the object, which is the JSON data containing the input, weight, date, etc. 
    s3.Object('bucket-name**', filename).put(Body=json.dumps({
        'input': input_str, 'weight': weight, 'date':date_str, 'time':time_str, 'day_of_week': day_of_week_str}))