from PIL import Image
import joblib
import streamlit as st

class LogisticRegressionClassifier:
    """
    A classifier for distinguishing between images of zeros and ones using logistic regression.

    Attributes:
        ones_directory (str): Path to the directory containing images of ones.
        zeroes_directory (str): Path to the directory containing images of zeros.
        classifier_model (LogisticRegression): The logistic regression model for classification.
    """

    def __init__(self, ones, zeroes):
        """
        Initializes the classifier with directories for images of ones and zeros.
        
        Args:
            ones (str): Path to the directory with images of ones.
            zeroes (str): Path to the directory with images of zeros.
        """
        self.ones_directory = ones
        self.zeroes_directory = zeroes
        self.classifier_model = None  # Model will be loaded later

    def load_model(self, model_path):
        """
        Loads the trained logistic regression model from a specified file.
        
        Args:
            model_path (str): The path where the model is saved.
        """
        self.classifier_model = joblib.load(model_path)
        print(f"Model loaded from {model_path}")

    def predict_image_class(self, test_image):
        """
        Predicts the class of an uploaded image (zero or one).
        
        Args:
            test_image (PIL.Image): The image to be classified.
        
        Returns:
            str: The predicted class label ('Zero' or 'One').
        """
        test_image = test_image.convert('L')  # Convert to grayscale
        test_image = test_image.resize((28, 28))  # Resize to 28x28
        pixel_values = list(test_image.getdata())  # Get pixel values
        pixel_values = [pixel_values]
        prediction = self.classifier_model.predict(pixel_values)
        label = 'One' if prediction[0] == 1 else 'Zero'
        return label

# Streamlit interface
st.title("Image Classifier (0/1)")
st.write("Upload an image to classify")

# Define paths for the model and images
ones = "D:/Testing/Ml/image_classification/Sample Images/One"
zeroes = "D:/Testing/Ml/image_classification/Sample Images/Zero"
model_path = 'logistic_model.pkl'

# Initialize the logistic regression classifier
digit_classifier = LogisticRegressionClassifier(ones, zeroes)

# Load the saved model
digit_classifier.load_model(model_path)

# Upload and classify an image
uploaded_image = st.file_uploader("Choose an image", type=["png", "jpg", "jpeg"])

if uploaded_image is not None:
    test_image = Image.open(uploaded_image)
    st.image(test_image, caption="Uploaded Image", use_column_width=True)
    prediction = digit_classifier.predict_image_class(test_image)
    st.write(f"Prediction: {prediction}")
