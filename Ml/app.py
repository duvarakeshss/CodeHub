import streamlit as st
import numpy as np
import tensorflow as tf
from PIL import Image, ImageOps

# Load the trained model with Streamlit's caching
@st.cache_resource
def load_model():
    return tf.keras.models.load_model('digit_classifier.h5')

class DigitClassifierApp:
    def __init__(self):
        # Call the cached load_model function
        self.model = load_model()

    # Preprocess the uploaded image
    def preprocess_image(self, image):
        # Convert the image to grayscale
        image = ImageOps.grayscale(image)
        # Resize the image to 28x28 pixels
        image = image.resize((28, 28))
        # Convert the image to a numpy array
        image_array = np.array(image)
        # Normalize the pixel values
        image_array = image_array.astype('float32') / 255
        # Reshape the array to (1, 28, 28, 1) for the model
        image_array = image_array.reshape(1, 28, 28, 1)
        return image_array

    # Run the Streamlit app interface
    def run(self):
        st.title('Digit Classifier')
        st.write("Upload an image of a handwritten digit (0-9) to predict it!")

        # Upload an image
        uploaded_image = st.file_uploader("Choose an image...", type=["jpg", "jpeg", "png"])

        if uploaded_image is not None:
            # Display the uploaded image
            image = Image.open(uploaded_image)
            st.image(image, caption="Uploaded Image", use_column_width=True)
            st.write("Classifying...")

            # Preprocess the image
            image_array = self.preprocess_image(image)

            # Make a prediction
            prediction = self.model.predict(image_array)
            predicted_digit = np.argmax(prediction)

            # Display the prediction
            st.write(f'Predicted Digit: {predicted_digit}')

# Run the app
if __name__ == "__main__":
    app = DigitClassifierApp()
    app.run()
