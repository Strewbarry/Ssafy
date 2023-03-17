<template>
  <div>
    <h1>아빠</h1>
    <div>{{ HalbeaData }}</div>
    <div>{{ HalbeaData2 }}</div>
    <button @click="changeHalbeaData">dfasdf</button>
    <ParentChild
      :HalbeaData="HalbeaData"
      :HalbeaData2="HalbeaData2"
      @chaangeHalbeaData="chaangeHalbeaData"
    />
  </div>
</template>

<script>
import ParentChild from "../components/ParentChild.vue";
export default {
  components: {
    ParentChild,
  },
  props: ["HalbeaData", "HalbeaData2"],
  methods: {
    changeHalbeaData() {
      this.$emit("changeHalbeaData", "랄랄라");
    },
    chaangeHalbeaData(text){
      this.$emit("changeHalbeaData", text)
    }
  },
};
</script>

<style></style>
